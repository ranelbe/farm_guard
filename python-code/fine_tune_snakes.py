import os
from PIL import Image
import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
from keras.applications import MobileNetV2
from keras.layers import Dense, GlobalAveragePooling2D
from keras.models import Model
from keras.preprocessing.image import ImageDataGenerator


#-------------------IMAGE PREPROCESSING------------------------------------------

# UNCOMMENT: to read the data from data directory to preprocess it and saves it in new_data

# #
# # base_source_dir = 'data'
# # base_target_dir = 'new_data'
# # sub_dirs = ['snakes', 'not_snakes']
# #
# # # Create target directories if they don't exist
# # for sub_dir in sub_dirs:
# #     target_sub_dir = os.path.join(base_target_dir, sub_dir)
# #     if not os.path.exists(target_sub_dir):
# #         os.makedirs(target_sub_dir)
# #
# #
# # def add_gaussian_noise(image, mean=0, sigma=25):
# #     """Add Gaussian noise to an image."""
# #     row, col, ch = image.shape
# #     gauss = np.random.normal(mean, sigma, (row, col, ch))
# #     noisy = np.clip(image + gauss, 0, 255)
# #     return noisy.astype(np.uint8)
# #
# #
# # def resize_images(source_sub_dir, target_sub_dir, size=(224, 224), simulated_size=(100, 100)):
# #     source_dir = os.path.join(base_source_dir, source_sub_dir)
# #     target_dir = os.path.join(base_target_dir, target_sub_dir)
# #
# #     for filename in os.listdir(source_dir):
# #         if filename.endswith(".JPG") or filename.endswith(".jpg"):  # You can add other formats if required
# #             img_path = os.path.join(source_dir, filename)
# #             with Image.open(img_path) as img:
# #                 # Resize to a lower resolution to simulate lower quality
# #                 img_low_res = img.resize(simulated_size, Image.LANCZOS)
# #
# #                 # Convert to numpy array to add noise
# #                 img_np = np.array(img_low_res)
# #
# #                 # Add Gaussian noise
# #                 img_noisy = add_gaussian_noise(img_np)
# #
# #                 # Convert back to PIL Image
# #                 img_noisy_pil = Image.fromarray(img_noisy)
# #
# #                 # Resize back to desired size
# #                 img_resized = img_noisy_pil.resize(size, Image.LANCZOS)
# #
# #                 target_path = os.path.join(target_dir, filename)
# #                 img_resized.save(target_path)
# #                 print(f"Processed and saved {filename} to {target_sub_dir}")
# #
# #
# # resize_images('snakes', 'snakes')
# #

#-------------------MODEL TRAINING------------------------------------------

# Load the base model
base_model = MobileNetV2(weights='imagenet', include_top=False)
x = base_model.output
x = GlobalAveragePooling2D()(x)
x = Dense(1024, activation='relu')(x)
predictions = Dense(1, activation='sigmoid')(x)
model = Model(inputs=base_model.input, outputs=predictions)

# Freeze base model layers
for layer in base_model.layers:
    layer.trainable = False

model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Load your dataset
# Define data augmentation for the training set
train_datagen = ImageDataGenerator(
    preprocessing_function=tf.keras.applications.mobilenet_v2.preprocess_input,
    validation_split=0.2,
    rotation_range=85,
    width_shift_range=0.5,
    height_shift_range=0.5,
    shear_range=0.6,
    zoom_range=[1.0, 1.7],
    horizontal_flip=True,
    brightness_range=[0.1, 1.9]
)


train_generator = train_datagen.flow_from_directory(
    'new_data',
    target_size=(224, 224),
    batch_size=32,
    class_mode='binary',
    subset='training'
)
validation_datagen = ImageDataGenerator(
    preprocessing_function=tf.keras.applications.mobilenet_v2.preprocess_input,
    validation_split=0.2
)

validation_generator = validation_datagen.flow_from_directory(
    'new_data',
    target_size=(224, 224),
    batch_size=32,
    class_mode='binary',
    subset='validation'
)

# Fine-tune the model
history = model.fit(train_generator, validation_data=validation_generator, epochs=5)

# Plot training & validation accuracy values
plt.figure(figsize=(12, 4))

plt.subplot(1, 2, 1)
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.title('Model accuracy')
plt.ylabel('Accuracy')
plt.xlabel('Epoch')
plt.legend(['Train', 'Validation'], loc='upper left')

# Plot training & validation loss values
plt.subplot(1, 2, 2)
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('Model loss')
plt.ylabel('Loss')
plt.xlabel('Epoch')
plt.legend(['Train', 'Validation'], loc='upper left')

plt.tight_layout()
plt.show()

# Save the model to a .pb file
model.save('fine_tuned_model')


#-------------------CREATE TRAINED MODEL------------------------------------------

# UNCOMMENT: to create a frozen_mode.pb
# import tensorflow as tf
#
# # Load the model
# model = tf.keras.models.load_model('fine_tuned_model')
#
# # Convert Keras model to ConcreteFunction
# full_model = tf.function(lambda x: model(x))
# full_model = full_model.get_concrete_function(
#     tf.TensorSpec(model.inputs[0].shape, model.inputs[0].dtype))
#
# # Get frozen ConcreteFunction
# from tensorflow.python.framework import convert_to_constants
# frozen_func = convert_to_constants.convert_variables_to_constants_v2(full_model)
# frozen_func.graph.as_graph_def()
#
# # Save the frozen graph
# tf.io.write_graph(graph_or_graph_def=frozen_func.graph,
#                   logdir=".",
#                   name="frozen_model.pb",
#                   as_text=False)
#
#

