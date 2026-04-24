FROM ghcr.io/qmk/qmk_cli:latest

ADD --keep-git-dir https://github.com/qmk/qmk_firmware.git?tag=0.32.12 /app/qmk_firmware

RUN <<-END
  apt-get -y update
  apt-get -y install python3-pip
  pip install keymap-drawer --break-system-packages
END

WORKDIR /app
ENV QMK_HOME=/app/qmk_firmware
ENV QMK_USERSPACE=/app/qmk_userspace
