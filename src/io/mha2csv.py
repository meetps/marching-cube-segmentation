import os
import mhaReader
import numpy as np

np.set_printoptions(threshold=np.nan)

DATA_PATH = '../../data/'

def crop_MRI(shape_MRI):
		rangeX = (shape_MRI[1]/2 -80,shape_MRI[1]/2 + 80)
		rangeY = (shape_MRI[2]/2 -80,shape_MRI[2]/2 + 80)
		rangeZ = (shape_MRI[3]/2 -80,shape_MRI[3]/2 + 80)
		ranges = (rangeX,rangeY,rangeZ)
		return ranges

def save_csv(data,filename,dirpath):
    with file(os.path.join(dirpath, filename) + '.csv', 'w') as outfile:
    	outfile.write(str(data.shape[1]) + " " + str(data.shape[2])+ " " +  str(data.shape[3]) + '\n')
    	for data_slice in data[0,:]:
        	np.savetxt(outfile, data_slice.astype(int) , fmt = '%i')

for dirpath, dirnames, filenames in os.walk(DATA_PATH):
	for filename in [f for f in filenames if f.endswith(".mha")]:
		if 'Flair' in filename:
					data_matrix   = mhaReader.fileIO(os.path.join(dirpath, filename))
					orig_data     = np.array([data_matrix.data])
					cropped_shape = crop_MRI(orig_data.shape)
					cropped_data  = orig_data[:,cropped_shape[0][0]:cropped_shape[0][1],cropped_shape[1][0] \
												:cropped_shape[1][1],cropped_shape[2][0]:cropped_shape[2][1]]
					# print(cropped_data[:,80,80,80])							
					# print(np.amax(cropped_data))							
					save_csv(cropped_data,'Flair',dirpath)