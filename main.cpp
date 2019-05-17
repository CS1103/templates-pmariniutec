#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <string>


int randomNumber(int start, int end){
  srand( time(NULL) );
  return rand() % end + start;
}

template <typename Iterator> 
void quickSort(Iterator start, Iterator end) {

  int size = (end - start);
  if ( size <= 0 )
	return;

  int indexPivot = randomNumber(0, size);
  auto pivot = start[indexPivot];

  if (indexPivot != 0)
	std::swap(*(start + indexPivot), *start);

  int i = 1;
  for (int j = 1; j < size; ++j){
	if (start[j] < pivot){
	  std::swap( *(start+j), *(start+i));
	  ++i;
	}
  }

  std::swap(start[0], start[i - 1]);

  quickSort(start, start + i - 1);
  quickSort(start + i, end);
}

int main(){

  std::vector<int> vec;
  std::vector<std::string> vec2;

  for (int i = 0; i < 100; ++i) {
    vec.push_back(rand() % 1000 - 50);
  }

  vec2.push_back("lk");
  vec2.push_back("asdas");
  vec2.push_back("A");
  vec2.push_back("C");
  vec2.push_back("72f8s");
  vec2.push_back("223");
  vec2.push_back("as88");
  vec2.push_back("hj");

  // int
  quickSort(vec.begin(), vec.end());
  for (auto &it : vec){
	std::cout << it << '\n';
  }

  std::cout << '\n';


  // strings
  quickSort(vec2.begin(), vec2.end());

  for (auto &it : vec2){
	std::cout << it << '\n';
  }

  return 0;
}

