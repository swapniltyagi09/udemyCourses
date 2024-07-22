#include <iostream>
#include <vector>
#include <fstream>
#include "../waveforms_files/waveforms.cpp"
#include "../waveforms_files/impulse_response.cpp"
#include <cmath>

extern std::vector<double> InputSignal_f32_1kHz_15kHz;
extern std::vector<double> Impulse_response;

std::vector<double> convolution(std::vector<double>,std::vector<double>);

int main(){

    std::ofstream signal_outFile("input_signal.dat");
    std::ofstream impulse_rsp_outFile("impulse_response.dat");
    std::ofstream convolution_result("output_signal.dat");

    for(auto i:InputSignal_f32_1kHz_15kHz)
        signal_outFile << i << std::endl;

    for(auto i:Impulse_response)
        impulse_rsp_outFile << i << std::endl;

    std::vector<double> conv_res = convolution(InputSignal_f32_1kHz_15kHz,Impulse_response);

    for(auto i:conv_res)
        convolution_result << i << std::endl;

    signal_outFile.close();
    impulse_rsp_outFile.close();
    convolution_result.close();

    return 0;
}

std::vector<double> convolution(std::vector<double> InputSignal_f32_1kHz_15kHz,std::vector<double> Impulse_response)
{
    int m = InputSignal_f32_1kHz_15kHz.size();
    int n = Impulse_response.size();

    int conv_length = m+n-1;
    std::vector<double> conv_res(conv_length);

    for(int i = 0; i < m ; i++)
        for(int j = 0; j < n ; j++)
            conv_res[i+j] += InputSignal_f32_1kHz_15kHz[i]*Impulse_response[j];

    
    return conv_res;

}