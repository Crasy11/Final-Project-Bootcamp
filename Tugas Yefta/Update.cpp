#include <stdio.h>
 struct date {
 	int orderTgl,orderBln,orderThn;
 };

struct carOrder {
 char userName[300], carName[400];
 struct date pickUp;
 struct date dropOff;
};
void update(){
 FILE *fp = fopen ("./isiorderan.txt", "r");
 FILE *fp2 = fopen ("./tampungansementara.txt", "w");
 struct carOrder car;
 while (fscanf(fp, "%[^#]#%[^#]#%d-%d-%d#%d-%d-%d\n",car.userName, car.carName, &car.pickUp.orderTgl, &car.pickUp.orderBln, &car.pickUp.orderThn, &car.dropOff.orderTgl, &car.dropOff.orderBln, &car.dropOff.orderThn ) != EOF){
  fprintf(fp2, "%s#%s#%d-%d-%d#%d-%d-%d\n", car.userName, car.carName, car.pickUp.orderTgl, car.pickUp.orderBln, car.pickUp.orderThn, car.dropOff.orderTgl, car.dropOff.orderBln, car.dropOff.orderThn);
 }
 fclose(fp);
 fclose(fp2);
 
 
  fp = fopen ("./isiorderan.txt", "w");
  fp2 = fopen ("./tampungansementara.txt", "r");

 while (fscanf(fp2, "%[^#]#%[^#]#%d-%d-%d#%d-%d-%d\n",car.userName, car.carName, &car.pickUp.orderTgl, &car.pickUp.orderBln, &car.pickUp.orderThn, &car.dropOff.orderTgl, &car.dropOff.orderBln, &car.dropOff.orderThn ) != EOF){
  fprintf(fp, "%s#%s#%d-%d-%d#%d-%d-%d\n", car.userName, car.carName, car.pickUp.orderTgl, car.pickUp.orderBln, car.pickUp.orderThn, car.dropOff.orderTgl, car.dropOff.orderBln, car.dropOff.orderThn);
 }
 fclose(fp);
 fclose(fp2);
}

int main(){
	update();
	
	return 0;
}
