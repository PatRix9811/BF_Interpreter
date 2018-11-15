#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>

void loop(char data,char *p)
{
	char *loop_data = NULL;
	bool in_loop = false;
	bool data_from_loop = false;
		switch (data)
		{
		case '>': { if (data_from_loop == in_loop)++p; break; }
		case '<': { if (data_from_loop == in_loop)--p; break; }
		case '+': { if (data_from_loop == in_loop){++(*p);} break;}
		case '-': { if (data_from_loop == in_loop)--(*p); break; }
		case '.': { if (data_from_loop == in_loop)putchar(*p); break; }
		case ',': { if (data_from_loop == in_loop)*p = getchar(); break; }
		case '[': { if (*p == 0) { data_from_loop = true; in_loop = false; } else { data_from_loop = true; in_loop = true; } break; }
		case ']': {if (in_loop) { } break; }
		default:break;
		}

	return;
}


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Required interpreted file source!!");
		return 1;
	}

	//OPEN FILE

	std::fstream f;
	f.open(argv[1], std::ios::in);

	if (!f.is_open())
	{
		printf("File cannot open!");
		return 1;
	}

	char pointer_table[30000] = { 0 };

	char *p=pointer_table;
	char *data=new char;
	while (!f.read(data,1).eof())
	{
		loop(*data, p);
	}

	return 0;
}