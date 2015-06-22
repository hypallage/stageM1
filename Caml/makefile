all: 
	ocamlbuild -yaccflag -v -lib unix latin.native; ln -fs latin.native Latin

byte: 
	ocamlbuild -yaccflag -v latin.byte

clean: 
	ocamlbuild -clean
