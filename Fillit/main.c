int  main(int argc, char **argv)
{
	int  fd;
 	int  count;
 	int  bytes;
 	char **tetris;
 	char *buf;
 	char **buffer;

 	if (argc != 2)
 	{
 	 ft_putstr("usage: fillit input_file\n");
 	 exit(0);
 	}
 	fd = open(argv[1], O_RDONLY);
 	if (fd == -1)
 	 error();
 	tetris = NULL;
 	buf = (char*)malloc(BUFF_SIZE + 1);
 	bytes = read(fd, buf, BUFF_SIZE + 1);
 	if (bytes == -1)
 	 error();
 	buf[bytes] = '\0';
 	count = count_tetriminos(buf);
 	if (validation(buf) == 1)
 	{
 		buffer = ft_strsplit(buf, '\n');
 		ft_test(buffer);	
 	}
 	else
 		error;
}
// 	 pos[0] = "...#";
// 	 pos[1] = "...#";
// 	 pos[2] = "...#";
// 	 pos[3] = "...#";

// 	 pos[4] = "....";
// 	 pos[5] = ".##.";
// 	 pos[6] = "..##";
// 	 pos[7] = "....";

// 	 pos[8] = "....";
// 	 pos[9] = ".##.";
// 	pos[10] = "..##";
// 	pos[11] = "....";

// 	pos[12] = "....";
// 	pos[13] = ".##.";
// 	pos[14] = "..##";
// 	pos[15] = "....";

// 	pos[16] = "....";
// 	pos[17] = ".##.";
// 	pos[18] = "..##";
// 	pos[19] = "....";

// 	pos[20] = "####";
// 	pos[21] = "....";
// 	pos[22] = "....";
// 	pos[23] = "....";

// 	pos[24] = "....";
// 	pos[25] = ".##.";
// 	pos[26] = "..##";
// 	pos[27] = "....";

// 	pos[28] = "....";
// 	pos[29] = ".##.";
// 	pos[30] = "..##";
// 	pos[31] = "....";

// 	pos[32] = "....";
// 	pos[33] = ".##.";
// 	pos[34] = "..##";
// 	pos[35] = "....";

// 	pos[36] = "....";
// 	pos[37] = "....";
// 	pos[38] = "..##";
// 	pos[39] = "..##";

//	pos[40] = "\0";