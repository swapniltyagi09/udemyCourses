#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "waveforms.cpp"

extern std::vector<double> InputSignal_f32_1kHz_15kHz;
double cal_signal_mean(std::vector<double>);

int main()
{

	double mean = cal_signal_mean(InputSignal_f32_1kHz_15kHz);
	std::cout<<"Mean = " << mean << std::endl;
	return 0;
}

double cal_signal_mean(std::vector<double> signal_src_vec){

	int sigLength = signal_src_vec.size();
	double mean = 0.0;

	for(auto i:signal_src_vec){
		mean = mean+i;
	}

	mean = mean/sigLength;
	return mean;
}