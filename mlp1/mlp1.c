#include "fann.h"
#include <stdio.h>

int main()
{

    const unsigned int num_input = 4;
    const unsigned int num_output = 3;
    const unsigned int num_layers = 3;
    const unsigned int num_neurons_hidden = 15;
    const float desired_error = (const float) 0.003;
    const unsigned int max_epochs = 100000;
    const unsigned int epochs_between_reports = 5000;

    struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    fann_train_on_file(ann, "entrada.data", max_epochs, epochs_between_reports, desired_error);

    fann_save(ann, "mlp1.net");

    fann_destroy(ann);

    return 0;
}

//5 - 0.0020827788
//10- 0.0024191623
