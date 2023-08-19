USER = ironhee
KEYBOARDS = dactyl_3x5_3 ploopy_classic ploopy_nano

# keyboard name
NAME_dactyl_3x5_3 = ironhee/dactyl_3x5_3
NAME_ploopy_classic = ploopyco/trackball
NAME_ploopy_nano = ploopyco/trackball_nano

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive
	git submodule update --remote
	# git submodule foreach make git-submodule

	# cleanup old symlinks and directory
	rm -rf qmk_firmware/keyboards/$(USER)
	rm -rf qmk_firmware/keyboards/$(NAME_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

	# add new symlinks and directory
	[ -d $(shell pwd)/configs/$@ ] \
		&& mkdir qmk_firmware/keyboards/$(USER) \
		&& ln -s $(shell pwd)/configs/$@ qmk_firmware/keyboards/$(USER)/$@ \
		&& mkdir -p qmk_firmware/keyboards/$(USER)/$@/keymaps \
		|| echo ''
	ln -s $(shell pwd)/keymaps/$@ qmk_firmware/keyboards/$(NAME_$@)/keymaps/$(USER)
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)

	# run lint check
	# cd qmk_firmware; qmk lint -km $(USER) -kb $(NAME_$@)

	# run build
	make  BUILD_DIR=$(shell pwd)/build -C qmk_firmware $(NAME_$@):$(USER)

	# cleanup symlinks and directory
	rm -rf qmk_firmware/keyboards/$(NAME_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/keyboards/$(USER)
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf qmk_firmware/keyboards/$(USER)
	rm -rf qmk_firmware/keyboards/$(NAME_dactyl_3x5_3)
	rm -rf qmk_firmware/keyboards/$(NAME_ploopy_classic)/keymaps/$(USER)
	rm -rf qmk_firmware/keyboards/$(NAME_ploopy_nano)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)
	rm -rf ./build/
	rm -rf ./qmk_firmware/