#include <stdio.h>
#include <string.h>

#define dis(x,j) x>j?x-j:j-x

int main()
{
	static unsigned short n, matriz[256], *ptr, i,j, actual[16], objetivos[16], anteriores[65536];
	static unsigned long long int *ptr2, *ptr3;

	scanf("%hu",&n);
	while(n!=0){
		ptr = actual;
		for(i=0;i<n;i++){
			scanf("%hu",ptr);
			ptr++;
		}
		ptr = objetivos;
		for(i=0;i<n;i++){
			scanf("%hu",ptr);
			ptr++;
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				matriz[(i*16)+j]=(dis(i,j))+(dis(actual[i],objetivos[j]));
			}
		}

		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%hu ",matriz[(i*16)+j]);
			}
			printf("\n");
		}

		ptr3 = (ptr2 = (unsigned long long int *) anteriores) + 16384;
		while(ptr2 != ptr3){
			*(ptr2++) = 0;
		}
		*ptr2 = 0;
		//for(i=0;i<16384*2*2;i++) printf("%hu",anteriores[i]);

		scanf("%hu",&n);
	}
	return 0;
}