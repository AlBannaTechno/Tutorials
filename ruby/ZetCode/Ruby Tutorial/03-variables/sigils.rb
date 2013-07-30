#!/usr/bin/env ruby

tree_name = "pine"  # local variable
$car_name = "Peugeot"  # global variable
@sea_name = "Black Sea"  # instance variable
@@species = "Cat"  # class variable

p local_variables
p global_variables.include? :$car_name
p self.instance_variables
p Object.class_variables
