//add include statements
#include "func.h"
#include<iostream>
#include <string>

using std::cout;

//add function code here
double get_gc_content(const std::string dna)
{
    double count;
    count = 0; 
    for (int i=0; i<dna.size(); i++)
{
    if( dna[i]=='G' || dna[i]=='C')
     {
         count++;
     }
}   
    return count/dna.size();
}
std::string get_reverse_string(std::string& dna)
{
    int len=dna.size();
    int n=len-1;
    for(int i=0; i<(len/2); i++)
    {
    char temp=dna[i];
    dna[i]=dna[n];
    dna[n]=temp;
    n=n-1;
    }
    return dna;
}
std::string get_dna_complement(std::string dna2)
{
    std::string dna=get_reverse_string(dna2);
    for (int i=0; i<dna.size(); i++)
    {
    if(dna[i]=='A')
    {
    dna[i]='T';
    }
    else if(dna[i]=='T')
    {
    dna[i]='A';
    }
    else if(dna[i]=='C')
    {
    dna[i]='G';
    }
    else if(dna[i]=='G')
    {
    dna[i]='C';
    }
    }
return dna;
}