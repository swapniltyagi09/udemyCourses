#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <fstream>
#include "../waveforms_files/waveforms.cpp"

std::vector<double> calc_sig_dft(std::vector<double>);
extern std::vector<double> InputSignal_f32_1kHz_15kHz;


int main(){

    std::vector<double> res_dft_sig = calc_sig_dft(InputSignal_f32_1kHz_15kHz);

    std::ofstream input_signal_file("input_signal.dat");
    std::ofstream out_dft_signal_file("output_dft_signal.dat");

    for(auto i:InputSignal_f32_1kHz_15kHz)
        input_signal_file << i << std::endl;

    for(auto i:res_dft_sig)
        out_dft_signal_file << i << std::endl;

    
    input_signal_file.close();
    out_dft_signal_file.close();

    return 0;

}

std::vector<double> calc_sig_dft(std::vector<double> InputSignal_f32_1kHz_15kHz){

    int sig_len = InputSignal_f32_1kHz_15kHz.size(); 
    std::vector<double> res_dft_sig_mag(sig_len);
    std::vector<double> res_dft_rex(sig_len);
    std::vector<double> res_dft_imx(sig_len);

    double PI = 3.14159265639;

    for(int i = 0 ; i < sig_len ; i ++)
    {
        for(int j = 0; j < sig_len ; j++)
        {
            res_dft_rex[i] = res_dft_rex[i] + InputSignal_f32_1kHz_15kHz[j]*cos((2*PI*i*j)/sig_len);
            res_dft_imx[i] = res_dft_imx[i] + (-1)*InputSignal_f32_1kHz_15kHz[j]*sin((2*PI*i*j)/sig_len);
        }

        res_dft_sig_mag[i] = sqrt(pow(res_dft_rex[i],2) + pow(res_dft_imx[i],2));
    }

    return res_dft_sig_mag;
    
}