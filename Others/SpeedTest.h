#include<bits/stdc++.h>
#include <chrono>
#include<windows.h>
using namespace std;

class Timer
{
private:
  using clock_type = std::chrono::high_resolution_clock;
  using second_type = std::chrono::duration<double, std::chrono::seconds::period>;
  using nano_type = std::chrono::duration<double, std::chrono::nanoseconds::period>;

  std::chrono::time_point<clock_type> m_startTime;

public:
  Timer() : m_startTime(clock_type::now())
  {
  }

  double reset()
  {
    double dt = getElapsed();
    m_startTime = clock_type::now();
    return dt;
  }

  double getElapsed() const
  {
    return std::chrono::duration_cast<second_type>(clock_type::now() - m_startTime).count();
  }

  double getNano() const
  {
    return std::chrono::duration_cast<nano_type>(clock_type::now() - m_startTime).count();
  }
};
