/*
 * Raspberry Pi PIC Programmer using GPIO connector
 * https://github.com/WallaceIT/picberry
 * Copyright 2014 Francesco Valla
 * Copyright 2017 Akimasa Tateba
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "../common.h"
#include "device.h"

using namespace std;

class pic10f322: public Pic{

	public:

		void enter_program_mode(void);
		void exit_program_mode(void);
		bool setup_pe(void){return true;};
		bool read_device_id(void);
		void bulk_erase(void);
		void dump_configuration_registers(void);
		void read(char *outfile, uint32_t start, uint32_t count);
		void write(char *infile);
		uint8_t blank_check(void);

	protected:
		void send_cmd(uint8_t cmd, unsigned int delay);
		uint16_t read_data(void);
		void write_data(uint16_t data);
		void reset_mem_location(void);

		/*
		* DEVICES SECTION
		*                    	ID       NAME           MEMSIZE
		*/
		pic_device piclist[4] = {{0x14D,  "PIC10F320", 0x100},
								{0x14C,  "PIC10F322", 0x200},
								{0x14F,  "PIC10LF320", 0x100},
								{0x14E,  "PIC10LF322", 0x200}};
};