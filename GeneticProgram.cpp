//Chris Myers: Genetic Program
#include <iostream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

 

int main()
{
    
    int pop_size = 8;
    int num_of_gen = 5;
    int gen_num = 2;
    int population[8];
    int n = sizeof(population)/sizeof(population[0]); 
    int mated_pop[pop_size/2];
  
  	//Populate Initial Generation
        srand(time(0));
        for(int i=0; i<pop_size; i++)
        {
            population[i]= rand() % 5 + 1;
        }
  	
    
  	//sort the population
        sort(population, population + n);
  
  	cout << "Initial Generation: " << "\n";
    
        for(int i=0; i<pop_size; i++)
        {
            cout << population[i] << ",";
        }
 
    //mating 	
     for(int i=1; i<num_of_gen; i++){
         
        int mate_index1 = 0;
        int mate_index2 = pop_size - 1;

        for(int i=0; i<pop_size/2; i++)
        {
            int case_index = rand()% 3 + 1;
            if(case_index == 1)
            {
      	         mated_pop[i] = population[mate_index1] + population[mate_index2];
    	       }
            
            else if(case_index == 2)
            {
      	         mated_pop[i] = population[mate_index2] - population[mate_index1];
    	       }
            
            else if(case_index == 3)
            {
      	         mated_pop[i] = population[mate_index1] * population[mate_index2];
    	       }
            
            mate_index1++;
            mate_index2--;
        }
    
     
    
         for(int i=0; i < pop_size/2; i++)
         {
            population[i] = mated_pop[i];
            }
         
         for(int i=pop_size/2; i<pop_size; i++)
         {
            population[i] = rand()% 5 +1;
            }
  
  	//sort the population
    sort(population, population + n);
  
    cout << "\n Generation number: " << gen_num << "\n";
    for(int i=0; i<pop_size; i++)
    {
        cout << population[i] << ",";
    }
         
        gen_num++;
    }
}

