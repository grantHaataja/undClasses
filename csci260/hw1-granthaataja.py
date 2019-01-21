# Grant Haataja: Homework 1

# loads the seaborn library
import seaborn as sns

# loads the titanic dataset
titanic = sns.load_dataset("titanic", data_home="~/PycharmProjects/seaborn-data")

print("The number of (rows, columns) in the titanic dataset:", titanic.shape)

print("\nThe following lists the column names and the data types of the columns:\n")

print(titanic.dtypes)

print("\nThe following data frame shows the first 10 rows of the titanic dataset:")

print("\n", titanic[0:10])

print(f"The mean of all data values are:\n\n{titanic.mean()}")
