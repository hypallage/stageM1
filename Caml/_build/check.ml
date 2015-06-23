open Parser

let rec printnumber latin corres line column=
	if (column=Array.length latin)
		then (if (line=16)
			then (print_char '\n';)
			else (print_char '\n';printnumber latin corres (line+1) 0))
		else (print_int  latin.(line).(column);print_char ' ';printnumber latin corres line (column+1))
;;

let rec printsymbols latin corres line column=
	if (column=Array.length latin)
		then (if (line=16)
			then (print_char '\n';)
			else (print_char '\n';printsymbols latin corres (line+1) 0))
		else (print_string  corres.(latin.(line).(column));print_char ' ';printsymbols latin corres line (column+1))
;;

let rec checkl latin corres posc posl line column=if (column=Array.length latin)
		then ()
		else (let number=latin.(line).(column) in
				if (posc.(column).(number)!=(-1))
					then raise (Twoapp (corres.(number),'c',column,posc.(column).(number),line))
					else (posc.(column).(number)<-line;if (posl.(line).(number)!=(-1))
						then raise (Twoapp (corres.(number),'l',line,posl.(line).(number),column))
						else (posl.(line).(number)<-column;checkl latin corres posc posl line (column+1)))
			)
;;

let rec checkm latin corres posc posl line=if (line=Array.length latin)
				then ()
				else (checkl latin corres posc posl line 0;checkm latin corres posc posl (line+1))
;;

let rec calculcycle latin posc posl lineh lineb vu start current rep=
		if (current=start)
		then (vu.(posl.(lineb).(current))<-true;start::rep)
		else (let column=posl.(lineb).(current) in 
			vu.(column)<-true;calculcycle latin posc posl lineh lineb vu start latin.(lineh).(column) (current::rep))
;;

let rec first latin vu n=if (n=Array.length latin)
		then n
		else (if (vu.(n))
			then first latin vu (n+1)
			else n)
;;


let rec calculcycleline latin posc posl lineh lineb vu rep=
	let start=first latin vu 0 in
	let cycle=calculcycle latin posc posl lineh lineb vu latin.(lineb).(start) latin.(lineh).(start) [] in 
	if (first latin vu 0=Array.length latin)
		then cycle::rep
		else calculcycleline latin posc posl lineh lineb vu (cycle::rep)
;;

let rec checkcycle latin posc posl rep lineh lineb=
		if (lineh=lineb)
		then (if (lineb=Array.length latin-1)
			then ()
			else checkcycle latin posc posl rep 0 (lineb+1))
		else (let vu=Array.create (Array.length latin) false in
			rep.(lineb).(lineh)<-calculcycleline latin posc posl lineh lineb vu [];
			checkcycle latin posc posl rep (lineh+1) lineb)
;;








