#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "123";
	char buffer[BUFSIZ/10+1];

	memset(buffer,'\0',sizeof(buffer));
	/*函数的参数是一个2个元素的数组，数组的元素是文件描述符，所以元素的本质是指针
	 * 只能从第0个元素读管道数据，从第1个元素中写进去*/
	if(pipe(file_pipes) == 0)//创建一个管道
	{
		printf("%d  %d",file_pipes[0],file_pipes[1]);
		data_processed = write(file_pipes[1],some_data,strlen(some_data));
		printf("Wrote %d bytes\n",data_processed);
		data_processed = read(file_pipes[0],buffer,BUFSIZ/10);
		printf("Read %d bytes\n",data_processed);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
