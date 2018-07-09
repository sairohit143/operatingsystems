#include<stdio.h>
#include<unistd.h>

int main()
{
int p[2];
int pid;
char inbuf[10],outbuf[10];
if(pipe(p)==-1)//error in pipe creation//
{
printf("pipe failed \n");
return 1;
}
else //pipe created succesfully//
{
pid=fork();//fork call to create child process//
if(pid)//code of parent process
{
printf("in parent process\n");
printf("type the data to be sent to child");
scanf("%s",outbuf);
//writing a message into the pipe
write(p[1],outbuf,sizeof(outbuf));//p(1) indicates write
sleep(2);// to allow the child to run
printf("after sleep in parent process \n");
}
else//coding of child process//
{
printf("in child process \n");
read(p[0],inbuf,10);//read the content written by parent
printf("the data recived by the child is %s \n",inbuf);
}
return 0;
}
}
