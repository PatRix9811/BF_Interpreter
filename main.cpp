#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>


void loop(char *data,char *p,int len,bool main_lp,int pos)
{
	for (int i = pos; i < len; i++)
	{
		
		switch (data[i])
		{
		case '>': { ++p;  break; }
		case '<': {--p;  break; }
		case '+': { ++(*p); break; }
		case '-': { --(*p); break; }
		case '.': { putchar(*p); break; }
		case ',': { *p = getchar(); break; }
		case '[': 
		{
			if (*p == 0)
			{
				int loop_beg=1;
				do
				{
					i++;
					if (data[i] == '[')loop_beg++;
					if (data[i] == ']')loop_beg--;
				} while (loop_beg != 0);

				break;
			}
			break;
		}
		case ']': 
		{
			int loop_beg = 1;
			do
			{
				i--;
				if (data[i] == '[')loop_beg--;
				if (data[i] == ']')loop_beg++;
			} while (loop_beg != 0);
			i--;
			break;
		}
		default:break;
		}
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

	f.seekg(0,f.end);
	int length = f.tellp();
	f.seekg(0,f.beg);

	char pointer_table[30000] = { 0 };
	char *p = pointer_table;
	char *data = new char[length];

	f.read(data, length);
	f.close();

	loop(data, p, length,true,0);

	return 0;
}