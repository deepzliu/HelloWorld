#include <stdio.h>
#include <string.h>

extern FILE *yyget_in ();
extern void yyrestart (FILE *input_file  );
int yyparse();
int lex_custom_input(char* buf, unsigned long *num_read,int max_read);
static int g_read_offset;

#define MAX_TEXT_LEN 1024
static char s_text_buf[MAX_TEXT_LEN];

int main() 
{
	int ret = 0;
	FILE *fyyout = NULL;

	while(1)
	{
		printf("[please input]: ");
		fgets(s_text_buf, MAX_TEXT_LEN, stdin);
		if(strlen(s_text_buf) <= 1)
		{
			break;
		}
		printf("[text input] %s\n", s_text_buf);

		g_read_offset = 0;
		ret = yyparse();
		if(ret != 0) 
		{
			yyrestart(yyget_in()); // 出错时重置状态
		}
		//fyyout = yyget_out();
	}
	return 0;
}


int lex_custom_input(char* buf, unsigned long *num_read,int max_read)
{
	int num_to_read = max_read;
	int remain = strlen(s_text_buf) - g_read_offset;
	
	if ( num_to_read > remain )
	{
		num_to_read = remain; 
	}

	memcpy(buf, s_text_buf + g_read_offset, num_to_read);
	
	*num_read = num_to_read;
	g_read_offset += num_to_read;

	return 0;
}


int simple_op(int n, int m, char *op)
{
	if(strncmp(op, "+", 1) == 0)
	{
		return n+m;
	}
	else if(strncmp(op, "-", 1) == 0)
	{
		return n-m;
	}
	return 0;
}
