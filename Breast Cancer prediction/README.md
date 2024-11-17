Project Description for Breast Cancer Prediction:
This project aims to predict the likelihood of breast cancer using a machine learning approach. The model leverages a dataset containing medical attributes derived from patient biopsy samples, which include features that describe the characteristics of cell nuclei. The goal is to classify cases as benign or malignant, helping in early detection and diagnosis.


Key Features of the Project:
Algorithms Used:

Support Vector Machines (SVM):
1.SVM is implemented to classify the data, leveraging its ability to find the optimal decision boundary between benign and malignant cases.
2.K-Nearest Neighbors (KNN):
KNN is also used to predict malignancy based on the proximity of samples to their nearest neighbors in the feature space.
Both algorithms are evaluated and compared for performance on the dataset.

Data Preprocessing:
1.Missing values in the BareNuc column are handled by filtering out records with non-numeric values.
2.All features are converted to integer types where applicable to ensure consistency.

Visualization:
1.Scatter plots are generated to compare features like Clump Thickness and Uniformity of Cell Size for benign and malignant cases.
2.Visual analysis aids in understanding the separability of the two classes.

Evaluation:
1.Metrics like accuracy, precision, and F1 score are used to evaluate both SVM and KNN models.
2.The dataset is split into training and testing sets to validate model performance.

Steps to Run the Project:
1. Clone the Repository:
git clone https://github.com/Saharfatemi22/SaharFatemi-Projects.git
cd SaharFatemi-Projects/Breast Cancer prediction
2.Install Required Libraries: Ensure the following Python libraries are installed:
pip install pandas numpy matplotlib scikit-learn
3.Run the Notebook:
Open the notebook file sahar fatemi-tamrine 3.ipynb in Jupyter Notebook or any Python IDE.
Follow the steps in the notebook to preprocess the data, train the models (SVM and KNN), and visualize results.
