/*******************************************************************************
 * Copyright (C) Lawrence Lo (https://github.com/galliumstudio). 
 * All rights reserved.
 *
 * This program is open source software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#include "qpcpp.h"
#include "event.h"
#include "qp_extras.h"

Q_DEFINE_THIS_FILE
  
char const * const eventName[] = {
    "NULL",
    "ENTRY",
    "EXIT",
    "INIT",
    "SYSTEM_START_REQ",
    "SYSTEM_START_CFM",
    "SYSTEM_STOP_REQ",
    "SYSTEM_STOP_CFM",
    "SYSTEM_TEST_TIMER",
    "SYSTEM_DONE",
    "SYSTEM_FAIL",
    
    "USER_LED_TOGGLE_REQ",
	
	"MIDI_UART_START_REQ",
	"MIDI_UART_START_CFM",
	"MIDI_UART_STOP_REQ",
	"MIDI_UART_STOP_CFM",
	"MIDI_UART_DATA_READY",
	"MIDI_UART_TIMEOUT",
	
	"FLASH_CONFIG_START_REQ",
	"FLASH_CONFIG_START_CFM",
	"FLASH_CONFIG_STOP_REQ",
	"FLASH_CONFIG_STOP_CFM",
	"FLASH_CONFIG_WRITE_CONFIGURATION",
	"FLASH_CONFIG_VERIFY_CONFIGURATION_REQ",
	"FLASH_CONFIG_WRITE_DONE",
	"FLASH_CONFIG_WRITE_WAVEFORMS_REQ",
	"FLASH_CONFIG_READ_LFO_REQ",
	"FLASH_CONFIG_READ_TO_LISTENER_REQ",
	"FLASH_CONFIG_READ_TO_LISTENER_DONE",
	
	"SD_START_REQ",
	"SD_START_CFM",
	"SD_STOP_REQ",
	"SD_STOP_CFM",
	"SD_READ_FILE_REQUEST",
	"SD_READ_FILE_RESPONSE",
	"SD_WRITE_FILE_REQ",
	"SD_WRITE_FILE_RESPONSE",
	
	"FPGA_START_REQ",
	"FPGA_START_CFM",
	"FPGA_STOP_REQ",
	"FPGA_STOP_CFM",
	"FPGA_WRITE_WAVE_FILE",
	"FPGA_WRITE_PWM",
	"FPGA_WRITE_FS",
	"FPGA_WRITE_PARAM_REQ",
	"FPGA_NOTIFY_KEY_PRESSED",
	"FPGA_SET_PORTAMENTO_REQ",
	"FPGA_SET_ENABLE_REQ",
	"FPGA_WRITE_WAVE_CFM",
	"FPGA_WRITE_VOL_REQ",
	
	"CAP_TOUCH_START_REQ",
	"CAP_TOUCH_START_CFM",
	"CAP_TOUCH_STOP_REQ",
	"CAP_TOUCH_STOP_CFM",
	"CAP_TOUCH_TOUCHED",
	
	"SYNTH_START_REQ",
	"SYNTH_START_CFM",
	"SYNTH_STOP_REQ",
	"SYNTH_STOP_CFM",
	"SYNTH_UPDATE_TIMER",
	"SYNTH_SET_CC_HANDLER",
	"SYNTH_SET_LFO_TARGET_REQ",
	"SYNTH_SET_LFO_RATE_REQ",
	"SYNTH_SET_MODE_PARAPHONIC_REQ",
	"SYNTH_SET_MODE_MONOPHONIC_REQ",
	"SYNTH_WAVEFORM_TIMER",
	"SYNTH_LOAD_PRESET_REQ",
	"SYNTH_STORE_PRESET_REQ"
		
	"MIDI_USB_START_REQ",
	"MIDI_USB_START_CFM",
	"MIDI_USB_STOP_REQ",
	"MIDI_USB_STOP_CFM",
	"MIDI_USB_DATA_READY",
	
	"NOTE_ON_REQ",
	"NOTE_OFF_REQ",
	"CONTROL_CHANGE_REQ",
	"PITCH_BEND_REQ",
	"AFTER_TOUCH_POLY_REQ",
	"AFTER_TOUCH_CHANNEL_REQ",
	"PROGRAM_CHANGE_REQ",
	"SYSTEM_EXCLUSIVE_REQ",
	
};  
  
char const * GetEvtName(QP::QSignal sig) {
    Q_ASSERT(sig < ARRAY_COUNT(eventName));
    if (sig < MAX_PUB_SIG) {
      return eventName[sig];
    }
    return "(UNKNOWN)";
}