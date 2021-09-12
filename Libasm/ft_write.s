;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   main.c                                             :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/05/06 10:15:52 by fmira             #+#    #+#             */
;*   Updated: 2021/05/06 10:15:52 by fmira            ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global _ft_write
extern ___error
section .text
_ft_write:                          ;rdi = file descriptor, rsi = string, rdx = byte count
    mov rax, 0x2000004              ;Write system call, addressing to the rax
    syscall                         ;Execute system call from rax
    jc _error
    ret
_error:
    push rax
    call ___error                   ;Get errno address: !NB! Mac - extern __error. Linux - extern __errno_location + ... WRT ..plt - linux routine for external calls
    pop qword[rax]
    mov rax, -1
    ret                             ;Return rax