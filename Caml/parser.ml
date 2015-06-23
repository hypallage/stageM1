exception Twoapp of (string*char*int*int*int);;
exception Inc of string;;

let rec check corres l cha d= if (l=d)
		then ()
		else (if (corres.(d)=cha)
			then raise (Twoapp (cha,'l',0,l,d))
			else check corres l cha (d+1))
;;

let rec read1lchar latin corres tring cha l n=if (n>=String.length tring)
				then (check corres l cha 0;
					corres.(l)<-cha;
					latin.(0).(l)<-l;)
				else
					(if (tring.[n]=' ')
					then (
						check corres l cha 0;
						corres.(l)<-cha;
						latin.(0).(l)<-l;
						read1lchar latin corres tring (String.make 0 'e') (l+1) (n+1))
					else (let s=String.make 1 tring.[n] in
					read1lchar latin corres tring (String.concat "" [cha;s]) l (n+1);
					))
;;

let rec search corres cha n= if (n>=Array.length corres)
				then raise (Inc cha)
				else
					(if (corres.(n)=cha)
					then (n)
					else search corres cha (n+1))
;;


let rec readlchar ligne latin corres tring cha l n=if (n>=String.length tring)
				then (let a=search corres cha 0 in
						latin.(ligne).(l)<-a;)
				else
					(if (tring.[n]=' ')
					then (
						let a=search corres cha 0 in
						latin.(ligne).(l)<-a;
						readlchar ligne latin corres tring (String.make 0 'e') (l+1) (n+1))
					else (let s=String.make 1 tring.[n] in
					readlchar ligne latin corres tring (String.concat "" [cha;s]) l (n+1);
					))
;;


let openlatin f=
	let fichier = open_in f in
	let s = input_line fichier in
	let size=int_of_string s in
	let corres=Array.create size "" in	
	let latin=Array.create_matrix size size 0 in
	
	let l1=input_line fichier in
	let rec readline line =
		try let s1 = input_line fichier in
			readlchar line latin corres s1 "" 0 0;
			readline (line+1)
		with End_of_file -> ()
	in read1lchar latin corres l1 "" 0 0;readline 1;(latin,corres);;



