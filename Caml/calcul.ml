open Parser

let rec checkl latin posc posl line column=if (column=Array.length latin)
		then ()
		else (let number=latin.(line).(column) in
				if (posc.(column).(number)<(line))
					then raise (Twoapp ("0",'c',column,posc.(column).(number),line))
					else (if (posl.(line).(number)<(column))
						then raise (Twoapp ("0",'l',line,posl.(line).(number),column))
						else (posc.(column).(number)<-line;posl.(line).(number)<-column))
			)
;;
