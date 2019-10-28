.name 	"zork 1234zork 1234zork 1234zork 1234zork
		1234zork 1234zork 1234zork 1234zork 1234zork
		zork 1234zork 12341234zork 1234zork 1234
		zork 1234zork 1234zork 1234zork 1234zork 1234
		zork 1234zork 1234zork 1234zork 1234zork 1234"
.comment "just a basic living prog"
l2:	    sti  r1,%:live, %1
		and  r1,%0,r1
live:   live     %1
		zjmp %:live
		and %:l2,-21,r12
		and-123,12,r2
		and 00123,12,r2
		and 123,12,r2 #bad
