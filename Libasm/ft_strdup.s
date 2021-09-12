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

global _ft_strdup
extern _malloc, _ft_strlen, _ft_strcpy
section .text                       ; rdi = string
_ft_strdup:
    xor rax, rax                    ; rax = 0
    push rdi                        ; save the string on the top of the stack frame
    call _ft_strlen                 ; rax = len of the rdi string
    inc rax                         ; rax++ (\0)
    mov rdi, rax                    ; move the length of the string to the rdi for allocation
    call _malloc                    ; allocate memory, resulting pointer is in the rax wrt ..plt - linux routine for external calls
    cmp rax, 0                      ; check if the result of the allocation == NULL
    je nullptr                      ; if yes, return the null pointer  
    pop rdi
    mov rsi, rdi
    mov rdi, rax
    call _ft_strcpy
    ret

nullptr:
    xor rax, rax                    ; rax = 0
    ret                             ; return NULL