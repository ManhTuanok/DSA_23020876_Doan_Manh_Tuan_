#include"list.cpp"

int main(){
    List list(100);

    for(int i=0;i<10;i++){
        list.addLast(i);
    }

    list.get(5);
    
}
    