//��������Ϸ��
//
//
//���⣺һ��������ÿ��������һ�����ӣ�ÿ�β����������ѡһ�����ϵ�����(x, y)��������i�е�j�е����ӣ�ѡ��һ����
//��(x, b)��(a, y)(����b < y��a < x)�����ӣ�Ȼ�������(x, y)һ��ת���޷����������䡣
//
//
//	������������Ϊ(x, y)�����ӿ��ɴ�С�ֱ�Ϊx��y������ʯ�ӣ�����ת��Ϊ�˾����Nim��Ϸ��������԰����ӿ���ʯ
//	�ӣ������Ȱ�Nim��Ϸ�е�һ��ʯ�ӿ���һ������������Nim��Ϸ�е�ÿ�β����ǰ�����һ����������С����ɾ����
//
//
//	��Ǹò�ƿ�����Ŀ��....
//	�ղ�YY��ò��ֻ�н�����ķ��������...���������ķ��ɷ���Ļ���������������(a, y)((x, b)����)��
//	��(x, y)��(a, y)����ȥ�����Ǿ�ʧȥ�� ʯ�����ֱ�Ϊ x, y, y, a���ĸ�ʯ�Ӷѡ�
//	��ԭ������ʯ�Ӷѵ�������W����ô����֮�������Ӧ���� W xor a xor y xor x xor y = W xor a xor x, Ҳ����˵��(x, y) (a, y)��ʹ ����W ��� W xor a xor x����ԭ�� ��һ�����淭һ������ ���͵ı仯ֵ ��ȻҲ�� W xor a xor x��Ҳ����˵ȷ��(x, y)��(a, y)֮������(a, y)�����滹�Ƿ��棬�������͵�Ӱ�춼����ͬ�ģ�����ѡ��һ�� ��x, y��֮������һ�����ӵ������ǲ�Ӱ������....
//	����ȫ�����泯�ϵ���������� �����е����궼����ʯ�ӶѾͿ�����....