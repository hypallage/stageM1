let rec printf_cycle corres cycle prefix fichier=match cycle with
| [] -> ()
| t::q -> (output_string fichier (String.concat "" [prefix;t]);printf_cycle corres q prefix fichier)
;;

let rec print_cycle corres cycle prefix=match cycle with
| [] -> (print_endline "";)
| t::q -> (print_string corres.(t);print_string " ";print_cycle corres q prefix)
;;

let rec print_cycle_line corres prefix cyclelist=match cyclelist with
| [] -> (print_endline "";)
| t::q -> (print_cycle corres t prefix;print_endline "";print_cycle_line corres prefix q)
;;

let rec printf_cycle_line corres prefix cyclelist fichier=match cyclelist with
| [] -> (print_endline "";)
| t::q -> (printf_cycle corres t prefix fichier;print_endline "";printf_cycle_line corres prefix q fichier)
;;
