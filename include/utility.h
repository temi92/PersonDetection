#pragma once 
#include <string>
#include <opencv2/core/utils/filesystem.hpp>
#include <opencv2/opencv.hpp>
#include <chrono>
inline std::string get_FileName(cv::String p){
    std::vector<std::string> tokens;
    char *token;
    token = strtok(const_cast<char*>(p.c_str()), "/");
    while (token != NULL){

        token = strtok(NULL, "/");
        if (token !=NULL){
            tokens.push_back(std::string (token));
        }

    }

    return tokens[tokens.size()-1];
}


inline std::string get_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

