#include "fann.h"
#include <stdio.h>

int main()
{

    const unsigned int num_input = 1;
    const unsigned int num_output = 1;
    const unsigned int num_layers = 3;
    const unsigned int num_neurons_hidden = 10;
    const float desired_error = (const float) 0.0003;
    const unsigned int max_epochs = 50000;
    const unsigned int epochs_between_reports = 1000;
    struct fann_train_data 	*train_data;

    struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
	
	train_data=fann_read_train_from_file("seno.data");

	//AQUI
	//fann_set_scaling_params(ann,train_data,-1.0,1.0,-1.0,1.0);
	//fann_scale_train(ann,train_data);
	//fann_scale_train_data(train_data,-1,1);	

    fann_train_on_data(ann, train_data, max_epochs, epochs_between_reports, desired_error);

    fann_save(ann, "mlp2.net");

    fann_destroy(ann);

    return 0;
}
