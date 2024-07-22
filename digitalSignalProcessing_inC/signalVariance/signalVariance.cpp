#include <iostream>
#include <cmath>
#include <vector>
#include "../waveforms_files/waveforms.cpp"

extern std::vector<double> InputSignal_f32_1kHz_15kHz;

double cal_signal_mean(std::vector<double>);
double cal_signal_variance(std::vector<double>,double);

int main()
{
    double mean = cal_signal_mean(InputSignal_f32_1kHz_15kHz);
	double variance = cal_signal_variance(InputSignal_f32_1kHz_15kHz,mean);
	std::cout<<"Variance = " << variance << std::endl;
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

double cal_signal_variance(std::vector<double> signal_src_vec,double mean){

	int sigLength = signal_src_vec.size();
	double variance = 0.0;

    for(auto i:signal_src_vec){
        variance = variance + pow((i - mean),2);
    }

    variance = variance/(sigLength-1);
	return variance;
}


