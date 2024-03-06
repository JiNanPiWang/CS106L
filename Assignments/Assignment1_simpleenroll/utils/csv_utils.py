import pandas as pd

def csv_to_binary(csv_filename, binary_filename):
    df = pd.read_csv(csv_filename)

    with open(binary_filename, 'wb') as file:
        df.to_pickle(file)

def binary_to_csv(binary_filename, csv_filename):
    df = pd.read_pickle(binary_filename)
    
    df.fillna('null', inplace=True)

    df.to_csv(csv_filename, index=False)
    

def files_are_equal(file1, file2):
    with open(file1, 'rb') as f1, open(file2, 'rb') as f2:
        while True:
            b1 = f1.read(4096)
            b2 = f2.read(4096)

            if b1 != b2:
                return False

            if not b1:
                return True
  
