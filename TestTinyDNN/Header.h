#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>

#include "tiny_dnn\tiny_dnn.h"

using namespace std;
using namespace tiny_dnn;

void test_dnn_get_layer_types(void);

void dnn_iris(size_t batch_size = 1, size_t epoch = 10);

void test_load_csv(string& fpath);

void test_load_iris(void);

void test_split_train_data(void);

/***
	Load a dataset from a path of file.
	@param fpath   input file path
	@param dst     destination of the dataset
	@return        success (true) of failure (false) in loading
***/
bool load_csv(string& fpath, vector<vector<string>> &dst);

/***
	Split a string by a delimiter.
	@param str          string to split
	@param delimiter    delimiter
	@return             a vector instance with split strings
***/
vector<string> split(string& str, char delimiter);

bool load_iris_vec_t(vector<vec_t> &X, vector<vec_t> &y);

/***
	Load a dataset of iris characteristics and labels.
	@param X       destination of characteristics
	@param y       destination of labels
	@return        success (true) of failure (false) in loading
***/
bool load_iris(vector<vector<float>> &X, vector<vector<int>> &y);

/***
	Load a dataset of iris characteristics and labels.
	@param X       destination of characteristics
	@param y       destination of labels
	@return        success (true) of failure (false) in loading
***/
bool load_iris(vector<vector<float>> &X, vector<int> &y);

/***
	Convert each label into value.
	@param y      labels
	@return       converted labels
***/
vector<int> labeling(vector<string> &y);

/***
	Convert each label into value.
	@param y      labels
	@return       converted labels
***/
vector<int> labeling(vector<int> &y);

/***
	Convert each label into value.
	@param y      labels
	@return       converted labels
***/
vector<int> labeling(vector<float> &y, float s = 0);

/***
Convert each label into vactor.
@param y      labels
@return       converted labels
***/
vector<vec_t> labeling_vec_t(vector<string> &y);

/***
	Convert each label into vactor.
	@param y      labels
	@return       converted labels
***/
vector<vector<int>> labeling_vector(vector<string> &y);

/***
	Convert each label into vactor.
	@param y      labels
	@return       converted labels
***/
vector<vector<int>> labeling_vector(vector<float> &y, float s = 0);

/***
	Split input datasets into train and test datasets.
	@param X            characteristics
	@param y            labels
	@param X_train      training characteristics
	@param y_train      training labels corresponding to X_train
	@param X_test       test characteristics
	@param y_test       test labels corresponding to X_test
	@param seed         seed of random number
	@param test_ratio   ratio of # of test datasets
***/
void split_train_data(const vector<vec_t> X, const vector<vec_t> y, 
	vector<vec_t> &X_train, vector<vec_t> &y_train, 
	vector<vec_t> &X_test, vector<vec_t> &y_test, 
	int seed = 0, double test_ratio = 0.3);