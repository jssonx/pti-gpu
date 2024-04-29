import torch
import torchvision
import intel_extension_for_pytorch as ipex

LR = 0.001
DOWNLOAD = True
DATA = "datasets/cifar10/"

transform = torchvision.transforms.Compose([
    torchvision.transforms.Resize((224, 224)),
    torchvision.transforms.ToTensor(),
    torchvision.transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5)),
])

train_dataset = torchvision.datasets.CIFAR10(
    root=DATA,
    train=True,
    transform=transform,
    download=DOWNLOAD,
)
train_dataset = torch.utils.data.Subset(train_dataset, range(len(train_dataset)//20))

train_loader = torch.utils.data.DataLoader(dataset=train_dataset, batch_size=64, shuffle=True)

model = torchvision.models.resnet50()
criterion = torch.nn.CrossEntropyLoss()
optimizer = torch.optim.SGD(model.parameters(), lr=LR, momentum=0.9)
model.train()

model = model.to("xpu")
criterion = criterion.to("xpu")
model, optimizer = ipex.optimize(model, optimizer=optimizer)

for epoch in range(1):
    running_loss = 0.0
    for batch_idx, (data, target) in enumerate(train_loader):
        data = data.to("xpu")
        target = target.to("xpu")

        optimizer.zero_grad()
        output = model(data)
        loss = criterion(output, target)
        loss.backward()
        optimizer.step()

        running_loss += loss.item()

        if (batch_idx + 1) % 10 == 0:
            print(f"Epoch: {epoch+1}/{1}, Batch: {batch_idx+1}/{len(train_loader)}, Loss: {running_loss/100:.4f}")
            running_loss = 0.0

print("Training finished")
