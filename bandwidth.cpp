/*
 * Problem:
 * Given a system that transmits data packets
 * and the probability of a packet loss being
 * 1/10, what is the bandwidth of the system.
 * Assume that the transmitter ALWAYS knows if
 * the packet was lost, and keeps on repeating
 * the transmission until the packet is sent
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const unsigned long long PACKET_NUM = 9999999999; // Maximum number of packets

int main() {
  // cout << PACKET_NUM << endl;
  srand(time(NULL));
  unsigned long long i = 0;
  int r;
  unsigned long long tries = 0;
  while (i < PACKET_NUM) {
    r = rand() % 100000;
    tries++;
    if (r >= 10000) {
      // next packet:
      i++;
    }
  }
  cout << "Number of packets sent:\t" << PACKET_NUM << endl;
  cout << "Number of tries it took:\t" << tries << endl;
  cout << "Bandwidth: " << PACKET_NUM*100.0 / tries << "% of the original" << endl;
}
