// Example 1: The very minimal ONNX inference in C++

#include <iostream>
#include <vector>

#include <onnxruntime/core/session/onnxruntime_cxx_api.h>

template <typename T>
void print(const T& t) {
    for (const auto & el: t)
        std::cout << el << " ";
}


int main(){
    using namespace std;
    
    // Create the "environment" with logger
    // Change this to ORT_LOGGING_LEVEL_INFO and see what happens !
    Ort::Env env(ORT_LOGGING_LEVEL_FATAL); 

    // Create session and load the ONNX file
    Ort::Session sess(env, "./m.onnx", Ort::SessionOptions());

    
    // Optional: Print inputs and outputs to the console
    if (true) {
        Ort::AllocatorWithDefaultOptions allocator;
        
        // Note: For older ORT versions, use sess.GetInputName() instead !
        int nIn = sess.GetInputCount();
        cout << "Inputs: " << nIn << " : " << endl;
        for (int i = 0; i < nIn; ++i) {
            cout << i << " : " << sess.GetInputNameAllocated(i, allocator).get() << endl;
        }

        int nOut = sess.GetOutputCount();
        cout << "Outputs: " << nOut << " : " << endl;
        for (int i = 0; i < nOut; ++i) {
            cout << i << " : " << sess.GetOutputNameAllocated(i, allocator).get() << endl;
        }
    }

    // Create data as float vectors
    vector<float> x{2.f, 1.f, -2.f};
    vector<float> y(2);
    // Wrap the data with ORT tensors (no copying)
    vector<Ort::Value> inputTensors;
    vector<Ort::Value> outputTensors;
    Ort::MemoryInfo memoryInfo = Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);
    int64_t shapeIn[] = {3};
    int64_t shapeOut[] = {2};
    inputTensors.push_back(Ort::Value::CreateTensor<float>(memoryInfo, x.data(), 3, shapeIn, 1));
    outputTensors.push_back(Ort::Value::CreateTensor<float>(memoryInfo, y.data(), 2, shapeOut, 1));

    vector<const char*> inputNames{"input1"};
    vector<const char*> outputNames{"output1"};

    sess.Run(Ort::RunOptions{nullptr}, inputNames.data(), inputTensors.data(), 1, outputNames.data(), outputTensors.data(), 1);

    // Print the result: should be -2 1
    cout << "y = ";
    print(y);
    cout << endl;


    return 0;
}
