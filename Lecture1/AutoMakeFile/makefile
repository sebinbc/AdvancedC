OBJ = f1 f2 f3
myProg = myProgram

$(myProg): $(OBJ)
	cc -o $(myProg) $(OBJ)

f1: f1.o
	cc -c f1.c

f2: f2.o
	cc -c f2.c

f3: f3.o
	cc -c f3.c
# you have to use the linux command "make depend" to #generate the dependencies
depend:
	cc -MM *.c >> mk.tmp
	sed '/^#DEPEND/q' makefile > mk.tmp
	mv mk.tmp makefile

#DEPEND: don't delete this!
 