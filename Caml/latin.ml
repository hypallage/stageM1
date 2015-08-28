open Parser
open Check
open Output
open Calcul

let main = let (latin,corres)=openlatin Sys.argv.(1) in
	let size=Array.length latin in
	printsymbols latin corres 0 0;
	printnumber latin corres 0 0;
	let posc=Array.create_matrix size size (-1) and posl=Array.create_matrix size size (-1) in
	checkm latin corres posc posl 0;
	let rep= Array.create_matrix size size [] in
	checkcycle latin posc posl rep 0 0;
	let fichier=open_out "resultat.dot" in
	output_string fichier "graph{\n";
	creefichier corres rep fichier 0 0	
;;

