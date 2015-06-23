


let rec printf_cycle corres cycle prefix fichier=match cycle with
| [] -> ()
| t::q -> (output_string fichier (String.concat "" [prefix;(string_of_int t)]);output_string fichier "--";printf_cycle corres q prefix fichier)
;;

let rec print_cycle corres cycle prefix=match cycle with
| [] -> ()
| t::q -> (print_string corres.(t);print_string " ";print_cycle corres q prefix)
;;

let rec print_cycle_line corres prefix cyclelist=match cyclelist with
| [] -> ()
| t::q -> (print_cycle corres t prefix;print_endline "";print_cycle_line corres prefix q)
;;

let rec printf_cycle_line corres prefix cyclelist fichier te=match cyclelist with
| [] -> ()
| t::q -> (let d=List.hd t in output_string fichier "edge [color=black];\n"; output_string fichier (String.concat "" [prefix;(string_of_int te);"--";prefix;(string_of_int d);";\n"]);
				output_string fichier "edge [color=red];\n";
				printf_cycle corres t prefix fichier;
				output_string fichier prefix;output_string fichier (string_of_int d);
		output_string fichier ";\n";printf_cycle_line corres prefix q fichier d)
;;

let rec nomnoeud corres (prefix:string) fichier n= if (n=Array.length corres)
				then ()
				else (output_string fichier prefix; output_string fichier (string_of_int n); output_string fichier " [label=\"";
					output_string fichier corres.(n);output_string fichier "\"];\n"; nomnoeud corres prefix fichier (n+1))
;;



let rec creefichier corres rep fichier lineh lineb=
		if (lineh=lineb)
		then (if (lineb=Array.length corres-1)
			then (output_string fichier "}";)
			else creefichier corres rep fichier 0 (lineb+1))
		else (let prefix=(String.concat "" ["l";(string_of_int lineh);"é";(string_of_int lineb);"é"]) in 
		output_string fichier prefix; output_string fichier (string_of_int 0); output_string fichier " [label=\"";
		output_string fichier (string_of_int lineh);output_string fichier " ";
		output_string fichier (string_of_int lineb);output_string fichier " ";
		output_string fichier corres.(0);output_string fichier "\"];\n";
		nomnoeud corres prefix fichier 1;printf_cycle_line corres prefix rep.(lineb).(lineh) fichier 0;creefichier corres rep fichier (lineh+1) lineb)
;;


