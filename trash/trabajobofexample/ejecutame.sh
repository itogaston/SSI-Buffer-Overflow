while [ 1 == 1 ]; do
	socat EXEC:./smtp.c.64.1.bin TCP-LISTEN:54472,fork,reuseaddr

	sleep 5;

done;
