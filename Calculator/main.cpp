#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int main(int argc, char **argv) {
    if (argc <= 1) { // если запускаем без аргументов, выводим справку
        std::cout <<"Количество аргументов: от 7 до 9"<< '\n' <<"Используйте калькулятор: -o [операция](mediana-медиана/ar-сред.ариф.) [операнд1] [операнд2] и так далее"<<'\n';
        return 0;
    }
    std::vector<int> a; // тут храним числа
    std::string oper; // операция
    int opt; // каждая следующая опция попадает сюда
    double sum=0;
    while((opt = getopt(argc, argv, "o:")) != -1) { // вызываем getopt пока она не вернет -1
        switch(opt) {
            case 'o': // в oper сохраняем оператор
            //optarg = type (std::string)
                oper = std::string(optarg);
                if(oper!="mediana" && oper!="ar"){ //обработка неверного ввода
    				std::cout << "Неправильно введена опция"<< "\n";
    				return 0;
    			}else{
                	for(int i=3; i<argc; i++){ //заполнение вектора числами
        				a.push_back(atoi(argv[i])); //Функция atoi преобразует строку string в целое значение типа int
        			}
        		}
                if (a.size()>9 or a.size()<7){
                    std::cout<<"Количество операндов не соответсвует указанному диапазону(7-9)"<<'\n';
                }
        		else {
                    if (oper=="mediana"){
                        std::sort(a.begin(), a.end());
                        if(a.size()%2!=0){
                            std::cout << "Медиана введенных числел = " << a[(a.size()-1)/2.0] << "\n";
        			}else{
            			std::cout << "Медиана введенных числел = "<< (a[a.size()/2]+a[(a.size())/2-1])/2.0 << "\n";
        			}
        			return 0;
                    }
                    if (oper=="ar"){ // среднее арифметическое
        			for(uint i=0; i<a.size(); i++){
        			sum+=a[i];
        			}
            		std::cout << "Среднее арифметическое введенных числел = "<< sum/a.size() << "\n";
        		}
        			return 0;
        }
                }
                
        		
    }
}
