#include <stdio.h>
#include <algorithm>
struct Node{
	int Galleon,Sickle,Knut;
};
using namespace std;
int main(int argc, char const *argv[])
{
	Node a=Node();
	Node b=Node();
	Node c=Node();
	scanf("%d.%d.%d",&a.Galleon,&a.Sickle,&a.Knut);
	scanf("%d.%d.%d",&b.Galleon,&b.Sickle,&b.Knut);
	c.Knut=(a.Knut+b.Knut)%29;
	c.Sickle=(a.Sickle+b.Sickle+(a.Knut+b.Knut)/29)%17;
	c.Galleon=a.Galleon+b.Galleon+(a.Sickle+b.Sickle+(a.Knut+b.Knut)/29)/17;
	printf("%d.%d.%d\n",c.Galleon,c.Sickle,c.Knut);
	system("pause");
	return 0;
}