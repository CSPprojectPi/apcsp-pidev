# include <stdio.h>

int main(){

int div = 3;

for(int x = 0; x < 100; x++){

	if(x % div == 0){
		printf("%d is divided by 3\n", x);
}
}

}
