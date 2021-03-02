all:	main.o live4.o live3.o live2.o Score.o Attack.o
	cc main.o live4.o live3.o live2.o Score.o Attack.o  -o cbb108011
	
main.o:	main.c
	cc main.c -c

live4.o: live4.c head.h
	cc live4.c -c
		
live3.o: live3.c head.h
	cc live3.c -c

live2.o: live2.c head.h
	cc live2.c -c
	
Score.o: Score.c head.h
	cc Score.c -c

Attack.o: Attack.c head.h
	 cc Attack.c -c

clean:
	 rm *.c~ *.h~ *.o *~
