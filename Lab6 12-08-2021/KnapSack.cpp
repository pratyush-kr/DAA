#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<iomanip>
#include<ctime>

int RandomProfit() {return rand() % 15 + 1;}
int RandomWeight() {return rand() % 25 + 1;}

class Object
{
    public:
        std::string obname;
        float profit;
        float weight;
        float pbyw;
        float parts;
        Object()
        {
            static int x;
            obname = "O" + std::to_string(++x);
            profit = RandomProfit();
            weight = RandomWeight();
            pbyw = profit/weight;
            parts = 1;
        }
        friend std::ostream& operator<<(std::ostream&, const Object&);
};

int comparePbyW(const Object &a, const Object &b) {return (a.pbyw > b.pbyw)? 1:0;}
int compareP(const Object &a, const Object &b) {return (a.profit > b.profit)? 1:0;}
int compareW(const Object &a, const Object &b) {return (a.weight > b.weight)? 1:0;}
std::vector<Object*> fillKnapSack(Object*, const int, int, const int, const char*);

void show(const Object *objects, int total)
{
    printf("Name Profit PbyW   Parts Weights\n");
    for(int i=0; i<total; i++)
        std::cout<<objects[i];
    std::cout<<"\n";
}

void show(const std::vector<Object*> KnapSack)
{
    float p = 0,w=0,x=0;
    printf("Knapsack: \n");
    printf("Name Profit PbyW   Parts Weights\n");
    for(int i=0; i<KnapSack.size(); i++)
    {
        p += KnapSack[i]->profit;
        w += KnapSack[i]->weight;
        std::cout<<*(KnapSack[i]);
    }
    printf("Total Profit = %.2f\nTotal Weight = %.2f\nObjects = %ld\n", p, w, KnapSack.size());
}

int main()
{
    std::vector<Object*> KnapSack;
    int total, capacity;
    std::cout<<"Total Objects: ";
    std::cin>>total;
    srand(time(0));
    Object objects[total];
    float weight;
    std::cout<<"Total Weight Knapsack can hold: ";
    std::cin>>weight;
    std::cout<<"Capacity: ";
    std::cin>>capacity;
    printf("Objects\n");
    show(objects, total);
    char sortby[10];
    std::cout<<"SortBy(PbyW, W, P): ";
    std::cin>>sortby;
    KnapSack = fillKnapSack(objects, total, weight, capacity, sortby);
    show(KnapSack);   
}

std::vector<Object*> fillKnapSack(Object *objects, const int total, int weight, int capacity, const char *sortby)
{
    std::vector<Object*> KnapSack;
    if(!strcmp(sortby, "P"))
        std::sort(&objects[0], &objects[total-1], compareP);
    else if(!strcmp(sortby, "W"))
        std::sort(&objects[0], &objects[total-1], compareW);
    else
        std::sort(&objects[0], &objects[total-1], comparePbyW);
    std::queue<Object*> Queue;
    for(int i=0; i<total; i++)
        Queue.push(&objects[i]);
    while(weight != 0 && capacity-- && Queue.size() != 0)
    {
        if(Queue.front()->weight < weight)
        {
            Object *ptr = Queue.front();
            KnapSack.push_back(ptr);
            weight -= ptr->weight;
            Queue.pop();
        }
        else
        {
            Object *ptr = Queue.front();
            float factor = ptr->weight/weight;
            ptr->weight = ptr->weight/factor;
            ptr->parts = ptr->parts/factor;
            ptr->profit = ptr->profit/factor;
            KnapSack.push_back(ptr);
            Queue.pop();
            weight = 0;
        }
    }
    return KnapSack;
}

std::ostream& operator<<(std::ostream &out, const Object &obj)
{
    using namespace std;
    out <<left<<setw(5)<<setprecision(3)<<obj.obname
        <<left<<setw(7)<<setprecision(3)<<obj.profit
        <<left<<setw(5)<<setprecision(3)<<obj.pbyw<<"  "
        <<left<<setw(8)<<setprecision(3)<<obj.parts
        <<left<<setw(8)<<setprecision(3)<<obj.weight<<"\n";
    return out;
}