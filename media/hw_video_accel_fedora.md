## Enabling hardware accelerated video encoding (Intel) on Fedora

### Installing
```
sudo dnf install https://mirrors.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm
sudo dnf install https://mirrors.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm
sudo dnf install intel-media-driver
sudo dnf install libva-utils
sudo dnf swap ffmpeg-free ffmpeg --allowerasing
sudo dnf group install multimedia
sudo dnf install intel-gpu-tools
```

### Checking
Run `vainfo` to check support and `intel_gpu_top` to see usage.

### Encoding
```
ffmpeg -i input.mp4 -c:v h264_qsv -b:v 5M output1.mp4
ffmpeg -i input.mp4 -c:v hevc_qsv -b:v 5M output2.mp4
```
