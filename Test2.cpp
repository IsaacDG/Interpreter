#include <iostream>

int main() {
    int tape[1000] = {0};
    int* dp = tape;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    while(*dp){
      dp++;
      (*dp)++;
      (*dp)++;
      (*dp)++;
      (*dp)++;
      while(*dp){
        dp++;
        (*dp)++;
        (*dp)++;
        dp++;
        (*dp)++;
        (*dp)++;
        (*dp)++;
        dp++;
        (*dp)++;
        (*dp)++;
        (*dp)++;
        dp++;
        (*dp)++;
        dp--;
        dp--;
        dp--;
        dp--;
        (*dp)--;
      }
      dp++;
      (*dp)++;
      dp++;
      (*dp)++;
      dp++;
      (*dp)--;
      dp++;
      dp++;
      (*dp)++;
      while(*dp){
        dp--;
      }
      dp--;
      (*dp)--;
    }
    dp++;
    dp++;
    char c = *dp;
    std::cout << c;
    dp++;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    char c = *dp;
    std::cout << c;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    char c = *dp;
    std::cout << c;
    char c = *dp;
    std::cout << c;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    char c = *dp;
    std::cout << c;
    dp++;
    dp++;
    char c = *dp;
    std::cout << c;
    dp--;
    (*dp)--;
    char c = *dp;
    std::cout << c;
    dp--;
    char c = *dp;
    std::cout << c;
    (*dp)++;
    (*dp)++;
    (*dp)++;
    char c = *dp;
    std::cout << c;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    char c = *dp;
    std::cout << c;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    (*dp)--;
    char c = *dp;
    std::cout << c;
    dp++;
    dp++;
    (*dp)++;
    char c = *dp;
    std::cout << c;
    dp++;
    (*dp)++;
    (*dp)++;
    char c = *dp;
    std::cout << c;
    return 0;
}