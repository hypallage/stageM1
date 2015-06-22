open Element

class latinrectangle number size = object
	val mutable line: int = 0
	val mutable size : int = size
	val mutable latin : element array array
	method get_line = line;
	method get_size = size;
	method set_size n = size<-n;

end;;

