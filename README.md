# project Themis

## ����Ϥʤ�?
¾�Υ饤�֥��䥢�ץꥱ�����������椹��Ȥ���
�ȤҲ����Ǥ��餦����Ū�ʥ����ɤ�
�饤�֥���Ż��Ƥ������ȴ�Ԧ������Ρ�

## Themis�Ȥ�?
[�����ƥߥ�][https://ja.wikipedia.org/wiki/%E3%83%86%E3%83%9F%E3%82%B9]��̾�������ڤ�����

## ����
* ���ˤ���̾ <themis/inttype.h>
* ����Ȥʤ������㳰���饹 <themis/except.h>

���ˤ���̾�ˤĤ��Ƥϡ������鿷�����񤯥����ɤǻȤդ䤦�ʤ�ΤǤϤʤ��Ȳ�ʤ���פա�&lt;cstdint&gt;��������줿̾����Ȥ������������̣�ǵ������餦��

## �Ȥ���
CMakeLists.txt���󶡤��Ƥ��Τǡ�������Ѥ�ƥ��󥹥ȡ��뤷�Ƥ�褤����
(���ΤȤ���)���Ƥ��إå��ե���������椵��Ƥ��Τǡ�
�إå��ե������Ŭ�ĤʤȤ���˥��ԡ�����include���ƻȤĤƤ�褤��

cmake���Ѥ�ƥ��󥹥ȡ��뤷����硢
libthemis�����Ѥ���ץ�����cmake��ȤĤ�build����ΤǤ���С�
CMakeLists.txt��
    find_package(themis REQUIRED)
    # ...
    target_link_libraries(targetname themis ...)
�Τ䤦�˽񤱤С�include path��Ŭ�����ꤷ�Ƥ���롢�Ϥ���
���ξ�硢�����������ɤ���ϡ�
    #include <themis/except.h>
�Τ䤦��include���롣

## �饤����
[�����BSD�饤����][https://opensource.org/licenses/BSD-2-Clause]�Ȥ��롣

## ���
oZ/acy (̾����)
* <acy@hiemalis.org>
* <http://www.hiemalis.org>

