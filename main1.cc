#include <iostream>
#include <iomanip>
#include <vector>


class TheFansAndMeetingsDivTwo {
public:
  double find(std::vector<int> minJ,
	      std::vector<int> maxJ,
	      std::vector<int> minB,
	      std::vector<int> maxB);
};

double TheFansAndMeetingsDivTwo::find(std::vector<int> minJ,
				      std::vector<int> maxJ,
				      std::vector<int> minB,
				      std::vector<int> maxB)
{
  double p = 0.0;

  int n = minJ.size();

  for (int i = 0; i < n; i ++) {
    int jm = minJ[i], jp = maxJ[i];

    for (int j = 0; j < n; j ++) {
      int bm = minB[j], bp = maxB[j];

      int xm = std::max(jm, bm);
      int xp = std::min(jp, bp);

      if (xm <= xp)
	p += (1.0 / n / n) * (xp - xm + 1.0) / (jp - jm + 1.0) / (bp - bm + 1.0);
    }
  }
  return p;
}


int main(int argc, char** argv)
{
  std::vector<int> minJ;
  std::vector<int> maxJ;
  std::vector<int> minB;
  std::vector<int> maxB;
  
  int n;

  std::cin >> n;

  for (int i = 0; i < n; i ++) {
    int j;
    
    std::cin >> j;

    minJ.push_back(j);
  }

  for (int i = 0; i < n; i ++) {
    int j;
    
    std::cin >> j;

    maxJ.push_back(j);
  }

  for (int i = 0; i < n; i ++) {
    int j;
    
    std::cin >> j;

    minB.push_back(j);
  }

  for (int i = 0; i < n; i ++) {
    int j;
    
    std::cin >> j;

    maxB.push_back(j);
  }

  std::cout <<
    std::setprecision(16) <<
    TheFansAndMeetingsDivTwo().find(minJ, maxJ, minB, maxB) <<
    std::endl;
}
