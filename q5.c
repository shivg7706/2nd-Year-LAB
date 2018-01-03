#include<stdio.h>
#include<string.h>
void main(int argc,char *argv[])	//receiving files through command line argument
{
int i,j,a,k,flag,y;
FILE *f1,*f2,*f3;			//FILE pointres assigned
char c,d[30],e[30],f;
if(argc<2)
printf("No file found");
else
printf("Files are: %s %s %s\n",argv[1],argv[2],argv[3]);
f1=fopen(argv[1],"r");	//file input opened
f2=fopen(argv[2],"r");	//file index opened
f3=fopen(argv[3],"w");	//file output opened
printf("File opened\n");
while(1)
{ 
i=0;

	while((f=getc(f2))!=32 && f!='\n')	//extracting the word one by one from index
	{
	if(f==EOF)
	break;
	e[i]=f;
	i++;
	}
	e[i]='\0';
	//printf("{%s}",e);
	y=strlen(e);
	while(1)
	{
		i=0;
		
			while((c=getc(f1))!=32 && c!='\n') //extracting the word one by one from input
			{
				if(c==EOF)
				break;
				d[i]=c;
				i++;
			}
			d[i]='\0';
		//printf("{%s %s}",d,e);
		if(c==EOF)
		break;
		for(i=0;d[i]!='\0';i++)				//for comparing the word of both file
		{
			flag=0;
			if(d[i]==e[0])
				{for(k=i,j=0;j<y;j++,k++)
				if(d[k]==e[j])
				flag++;
			if(flag==y)					//writing the word to output file
			{
			for(i=0;d[i]!='\0';i++)				
			putc(d[i],f3);
			putc(32,f3);
			break;				
			}}
		}
	}
rewind(f1);		//setting pointer of file input to beginning
if(f==EOF)
break;
}
fclose(f1);		//close file input
fclose(f2);		//close file index
fclose(f3);		//close file output
printf("Process has been completed\n");
}
